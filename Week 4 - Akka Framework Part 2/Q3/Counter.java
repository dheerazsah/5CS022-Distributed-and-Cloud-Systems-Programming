package number3;

import akka.actor.AbstractActor;
import akka.actor.AbstractActor.Receive;

public class Counter extends AbstractActor{
	
	
	private int count;
	
	Counter(){
		count = 0;	
	}
	
	@Override
	 public Receive createReceive() {
	        return receiveBuilder()
	           .match(MessageA.class, this::onMessageA)
	           .build();
	    }
	
	private void onMessageA(MessageA msg) {
		count++;
		System.out.printf("Counter: %d \n",count);
		
	}

}
