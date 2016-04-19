VPATH=some_ccpp_question

targ=$(shell ls some_ccpp_question|grep cpp|grep -v ccpp|xargs)
objs=$(patsubst %.cpp,%,$(targ))

all:$(objs)
	echo $(targ)

%:%.cpp
	g++ -o $@ $< -lm -std=c++11
.PHONY:clean

clean:
	rm $(objs)

