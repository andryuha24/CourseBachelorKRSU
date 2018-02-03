
public class NotificationTest {

    private volatile boolean go = false;

    public static void main(String args[]) throws InterruptedException {
        final NotificationTest test = new NotificationTest();
      
        Runnable waitTask = new Runnable(){
            public void run(){
                try {
                    test.shouldGo();
                } catch (InterruptedException ex) {}
                System.out.println(Thread.currentThread() + " finished");
            }
        };
      
        Runnable notifyTask = new Runnable(){

            public void run(){
                test.go();
                System.out.println(Thread.currentThread() + " finished");
            }
        };
      
        Thread t1 = new Thread(waitTask, "WT1");
        Thread t2 = new Thread(waitTask, "WT2"); 
        Thread t3 = new Thread(waitTask, "WT3");
        Thread t4 = new Thread(notifyTask,"NT1");
        t1.start();
        t2.start();
        t3.start();
        Thread.sleep(200);

        t4.start();
      
    }

    private synchronized void shouldGo() throws InterruptedException {
        while(go != true){
            System.out.println(Thread.currentThread()
                         + " is going to wait on this object");
            wait();
            System.out.println(Thread.currentThread() + " is woken up");
        }
        go = false;
    }
    private synchronized void go() {
        while (go == false){
            System.out.println(Thread.currentThread());
            go = true;
            notifyAll();
        }
      
    }
  
}