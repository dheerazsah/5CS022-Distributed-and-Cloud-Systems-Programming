package number2;

import akka.actor.ActorRef;
import akka.actor.ActorSystem;
import akka.actor.Props;
import java.io.IOException;

class Main {

    public static void main(String[] args) {

        ActorSystem system = ActorSystem.create();
        ActorRef actorARef = system.actorOf(Props.create(ActorA.class));
        actorARef.tell("Hello!",actorARef);
        actorARef.tell(10,actorARef);
        actorARef.tell(50,actorARef);
        actorARef.tell(1000,actorARef);
        actorARef.tell(40.0,actorARef);
        actorARef.tell(433.45545458,actorARef);
        actorARef.tell(2147483647,actorARef);
        actorARef.tell(true,actorARef);

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
