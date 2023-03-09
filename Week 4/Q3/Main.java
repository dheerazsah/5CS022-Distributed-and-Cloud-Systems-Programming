package number3;

import akka.actor.ActorRef;
import akka.actor.ActorSystem;
import akka.actor.Props;
import java.io.IOException;
import java.util.ArrayList;

class Main {

    public static void main(String[] args) {

        ActorSystem system = ActorSystem.create();
        ActorRef counterARef = system.actorOf(Props.create(Counter.class));
        
 
        for(int i = 0; i < 10; i++) {
        	
        	ActorRef actorRef = system.actorOf(Props.create(ActorA.class));
        	actorRef.tell(new MessageA("Hello"), counterARef);
     
        }
        

        try {
            System.out.println("Press ENTER to end program.");
            System.in.read();
        }
        catch (IOException ignored) { }
        finally {
            system.terminate();
            System.out.println("Akka System Terminated.");
        }
    }

}
