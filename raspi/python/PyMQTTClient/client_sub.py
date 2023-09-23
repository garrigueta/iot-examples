import paho.mqtt.client as paho

def on_message(mosq, obj, msg):
    print("%-20s %d %s" % (msg.topic, msg.qos, msg.payload))
    mosq.publish('pong', 'ack', 0)

def on_publish(mosq, obj, mid):
    pass

if __name__ == '__main__':
    client = paho.Client()
    client.on_message = on_message
    client.on_publish = on_publish

    client.connect("192.168.1.140", 1883, 60)

    client.subscribe("env/test/TEMPERATURE", 0)

    while client.loop() == 0:
        pass