Flight localFlight = null;
        Passenger localPassenger = null;
        try {
            int fid = Integer.parseInt(sfid2.substring(1));
            localFlight = db.findFlight(fid);
            if (localFlight == null) return;
            CCM.lockX(localFlight, this);
            if (localFlight.flightFull()) return;
            //if (Cancel(sfid,pid))
            //    Reserve(sfid2,pid);
            boolean flag = true;
            localPassenger = db.findPassenger(pid);

            if (localPassenger == null || localFlight == null) {
                return;
            }
            CCM.lockX(localPassenger, this);
            if (flag) {
                flag = localFlight.removePassenger(db.findPassenger(pid));
            }
        }
        finally{
            if(localPassenger!=null)
                CCM.unlock(localPassenger,this);
            if(localFlight!=null)
                CCM.unlock(localFlight,this);
            CCM.unlock(localFlight,this);   
        }