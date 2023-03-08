package number3;

import akka.actor.AbstractActor;
import akka.actor.ActorRef;
import akka.actor.Props;
import akka.event.Logging;
import akka.event.LoggingAdapter;

public class ActorA extends AbstractActor {
	
	LoggingAdapter log = Logging.getLogger(getContext().system(), this);

    @Override
    public Receive createReceive() {
        return receiveBuilder()
                .match(MessageA.class, this::onMessageA)
                .build();
    }

    private void onMessageA(MessageA msg) {
    	
    	ActorRef counter = getSender();
    	counter.tell(new MessageA("Message"),getSelf());
    	
    }

}