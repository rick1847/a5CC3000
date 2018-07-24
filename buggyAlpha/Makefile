#-Werror for later
CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall  -Werror=vla -MMD -g
FILES=${wildcard *.cc}\
	${wildcard map/Cell/*.cc} \
	${wildcard map/Floor/*.cc} \
	${wildcard display/*.cc} \
	${wildcard item/*.cc} \
	${wildcard item/gold/*.cc} \
	${wildcard item/potions/*.cc} \
	${wildcard character/*.cc} \
	${wildcard character/playerRace/*.cc} \
	${wildcard character/enemyRace/*.cc} \

OBJS=${FILES:.cc=.o}
DEPS=${OBJS:.o=.d}
EXEC=main
ONAME=a4q1
${EXEC}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${ONAME}

-include ${DEPS}

clean:
	rm ${OBJS} ${DEPS} ${ONAME}
.PHONY: clean 
