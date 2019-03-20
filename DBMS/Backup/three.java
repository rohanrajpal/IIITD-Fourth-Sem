
//        ArrayList<Transaction> arr = new ArrayList<>();
//        ArrayList<Transaction2PL> arr2PL = new ArrayList<>();


//        Transaction trans1 = new Transaction(cm,db,"F2",1,1,"F2");
//        arr.add(trans1);
//
//        Transaction trans2 = new Transaction(cm,db,"F1",2,1,"F2");
//        arr.add(trans2);
//
//        Transaction trans3 = new Transaction(cm,db,"F2",1,2,"");
//        arr.add(trans3);
//
//        Transaction trans4 = new Transaction(cm,db,"F1",2,5,"F2");
//        arr.add(trans4);
//
//        Transaction trans5 = new Transaction(cm,db,"F1",2,3,"F3");
//        arr.add(trans5);
//
//        Transaction trans6 = new Transaction(cm,db,"F1",2,4,"");
//        arr.add(trans6);
//
//        Transaction2PL trans2PL1 = new Transaction2PL(cm,db,"F2",1,1,"F2");
//        arr2PL.add(trans2PL1);
//
//        Transaction2PL trans2PL2 = new Transaction2PL(cm,db,"F1",2,1,"F2");
//        arr2PL.add(trans2PL2);
//
//        Transaction2PL trans2PL3 = new Transaction2PL(cm,db,"F2",1,2,"F2");
//        arr2PL.add(trans2PL3);

//        Transaction2PL trans2PL4 = new Transaction2PL(cm,db,"F1",2,5,"F2");
//        arr2PL.add(trans2PL4);
//
//        Transaction2PL trans2PL5 = new Transaction2PL(cm,db,"F1",2,3,"F2");
//        arr2PL.add(trans2PL5);
//
//        Transaction2PL trans2PL6 = new Transaction2PL(cm,db,"F1",2,4,"F2");
//        arr2PL.add(trans2PL6);
//
//        ExecutorService execserial = Executors.newFixedThreadPool(2);
//        for (Transaction2PL elem: arr2PL){
//            Thread t = new Thread(elem);
//            t.start();
//            t.join();
//        }
//
//        if (!execserial.isTerminated()){
//                execserial.shutdown();
//                execserial.awaitTermination(10000, TimeUnit.MILLISECONDS);
//            }

//        execserial = Executors.newFixedThreadPool(2);
//        execserial.execute(trans6);
//        t3.join();
//        t4.join();
//        t5.join();
//        t6.join();

//        db.printDetails();
//        t5.join();
//        t1.join();
//


//        t3.start();
//        t3.join();

////        db.printDetails();
//        t4.start();
//        t4.join();
////        db.printDetails();
//
//        t5.start();
//        t5.join();
//
//        t6.start();
//        t6.join();
//

//        rand.setSeed(0);
//        HashMap<Integer,Integer> hm =  new HashMap<>();