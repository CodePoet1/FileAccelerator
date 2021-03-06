CC=gcc
CPP=g++
CFLAGS=-c -Wall -g
LDFLAGS=-lc -g
LDFLAGS_CPP= -g

EXECUTABLE_SEND=dgsend
SOURCES_SEND=dgsend.c dgram.c
OBJECTS_SEND=$(SOURCES_SEND:.c=.o)

EXECUTABLE_RECV=dgrecv
SOURCES_RECV=dgrecv.c dgram.c
OBJECTS_RECV=$(SOURCES_RECV:.c=.o)

EXECUTABLE_FA=fa
SOURCES_FA=main.cpp setup/setup.cpp
OBJECTS_FA=$(SOURCES_FA:.cpp=.o)

#############################################
# Commands for main FileAccelerator cpp code#
#############################################
fa: $(SOURCES_FA)

$(EXECUTABLE_FA): $(OBJECTS_FA)
	$(CPP) $(LDFLAGS_CPP) $(OBJECTS_FA) -o $@
	echo Make Done

clean_fa:
	rm -rf $(EXECUTABLE_FA) $(OBJECTS_FA)
	echo Clean Done


#############################################
# Commands for send side of code            #
#############################################
send: $(SOURCES_SEND) $(EXECUTABLE_SEND)

$(EXECUTABLE_SEND): $(OBJECTS_SEND)
	$(CC) $(LDFLAGS) $(OBJECTS_SEND) -o $@
	echo Make Done  	

clean_send:
	rm -rf *o $(EXECUTABLE_SEND)
	echo Clean Done


#############################################
# Commands for recv side of code            #
#############################################
recv: $(SOURCES_RECV) $(EXECUTABLE_RECV)

$(EXECUTABLE_RECV): $(OBJECTS_RECV)
	$(CC) $(LDFLAGS) $(OBJECTS_RECV) -o $@
	echo Make Done  	


clean_recv:
	rm -rf *o $(EXECUTABLE_RECV)
	echo Clean Done

#############################################
# Generic commands                          #
#############################################
.c.o: 
	$(CC) $(CFLAGS) $< -o $@


.cpp.o:
	$(CPP) $(CFLAGS) $< -o $@

