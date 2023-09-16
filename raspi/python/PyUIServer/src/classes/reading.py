class Reading:

    def __init__(self, data, value, host, time):
        self.__data = str(data)
        self.__value = str(value)
        self.__host = str(host)
        self.__time = str(time)

    @property
    def out(self):
        return self.__data + " " + self.__value + " " + self.__host + " " + self.__time

    @property
    def data(self):
        return self.__data
    
    @data.setter
    def data(self, value):
        self.__data = value

    @property
    def value(self):
        return self.__value
    
    @value.setter
    def value(self, value):
        self.__value = value

    @property
    def host(self):
        return self.__host
    
    @host.setter
    def host(self, value):
        self.__host = value

    @property
    def time(self):
        return self.__time
    
    @time.setter
    def time(self, value):
        self.__time = value