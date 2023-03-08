package com.example;

import akka.actor.AbstractActor;
import akka.actor.ActorRef;
import akka.actor.Props;

public class ActorA extends AbstractActor {

    @Override
    public Receive createReceive() {
        return receiveBuilder()
                .match(MessageA.class, this::onMessageA)
                .build();
    }

    private void onMessageA(MessageA msg) {
        System.out.println("Actor A received Message A : "+ msg.text + " from " + getSender());
    }

}