
########  SHIDFAR made Changes Here  #############
CC = g++
################# END ######################

CFLAGS = -O2 -fPIC -ggdb -I. -DPOSIX

########  SHIDFAR made Changes Here  #############
#adding c++11 compilers for pthreads
CFLAGS = -std=c++11

# CC= gcc

MYSQLCFLAGS= -I/usr/include/mysql -DBIG_JOINS=1 -fno-strict-aliasing -g
MYSQLLIBS= -L/usr/lib/arm-linux-gnueabihf -lmysqlclient -lpthread -lz -lm -lrt -ldl

sql: sql.c
	$(CC) sql.c -o sql $(MYSQLCFLAGS) $(MYSQLLIBS)
	chmod 555 sql


################# END ######################
########### Shidfar Hodizoda ###############

.cpp.o:
	${CXX} $(CFLAGS) -c $< -o $@

# ********************************************************************************************
#	MAIN APPLICATION SECTION
# ********************************************************************************************

LDFLAGS = -lmosquittopp -lsqlite3 -ljsoncpp -lpthread -lmysqlcppconn `mysql_config --cflags --libs`
SOURCES = main.cpp
EXECUTABLE = mysqler
OBJECTS = $(SOURCES:.cpp=.o)

$(EXECUTABLE): $(OBJECTS)
	${CXX} $(CFLAGS) -o $@ $^ $(LDFLAGS)

# ********************************************************************************************
#	CLEAN UP SECTION
# ********************************************************************************************
clean:
	rm -rf *.o
	rm -rf `find . -name *.o`
	rm -rf *.so
	rm -rf $(EXECUTABLE) eesocket
#---------------------
	rm -f sql


all: $(LIBRARY) $(SQLITEPLUGINNAME) $(PLUGINNAME) $(EXECUTABLE)
