from __future__ import print_function
from sqlite3 import connect
from src.classes.reading import Reading


class SqliteClient:

    def __init__(self, db_path):
        self.db_path = db_path
        self.conn = connect(self.db_path)
        self.curs = self.conn.cursor()


    def __del__(self):
        self.conn.close()


    def insert_reading_values(self, data, value, host, time):
        self.curs.execute(
            "INSERT INTO prices VALUES('" +
            data + "', '" +
            value + "', '" +
            host + "', " +
            str(time) + ");")
        self.conn.commit()

    def insert_reading_object(self, reading: Reading):
        self.curs.execute(
            "INSERT INTO readings VALUES('" +
            reading.data + "', '" +
            reading.value + "', '" +
            reading.host + "', " +
            str(reading.time) + ");")
        self.conn.commit()


    def print_readings(self):
        # Replace username with your own A2 Hosting account username:
        self.curs.execute("SELECT data, value, host, time FROM readings;")
        for data, value, host, time in self.curs.fetchall():
            print(data, value, host, time)


    def init_readings(self):
        self.curs.execute(
            "CREATE TABLE IF NOT EXISTS readings ("
            "data varchar(32), value varchar(32), host varchar(32), "
            "time datetime);")
        self.conn.commit()
