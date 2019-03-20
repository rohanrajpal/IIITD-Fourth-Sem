HashMap<Integer,Integer> hm=  new HashMap<>();
        for (int i=1;i<=4;i++){
            Random rand = new Random(0);
            ExecutorService execserial = Executors.newFixedThreadPool(i);
            long start = System.currentTimeMillis();
            int n=0;
            while (n<100) {
                execserial.execute(new Transaction(cm, db,rand));
                n++;
            }


            //System.out.println(i+" "+ Transaction.trans_ended_cnt);
            //hm.put(i,Transaction.trans_ended_cnt);


            if (!execserial.isTerminated()){
                execserial.shutdown();
                execserial.awaitTermination(5L, TimeUnit.SECONDS);
            }
            System.out.println(i+" "+100.0/(System.currentTimeMillis()-start));
            //Transaction.trans_ended_cnt = 0;
        }