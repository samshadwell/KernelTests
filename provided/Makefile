#
#	Sample Makefile for COMP 421 Yalnix kernel and user programs.
#
#	The Yalnix kernel built will be named "yalnix".  *ALL* kernel
#	Makefiles for this lab must have a "yalnix" rule in them, and
#	must produce a kernel executable named "yalnix" -- we will run
#	your Makefile and will grade the resulting executable
#	named "yalnix".
#
#	Your project must be implemented using the C programming
#	language (e.g., not in C++ or other languages).
#

#
#	Define the list of everything to be made by this Makefile.
#	The list should include "yalnix" (the name of your kernel),
#	plus the list of user test programs you also want to be mae
#	by this Makefile.  For example, the definition below
#	specifies to make Yalnix test user programs test1, test2,
#	and test3.  You should modify this list to the list of your
#	own test programs.
#
#	For each user test program, the Makefile will make the
#	program out of a single correspondingly named sourc file.
#	For example, the Makefile will make test1 out of test1.c,
#	if you have a file named test1.c in this directory.
#

ALL = bigstack blowstack brktest console delaytest exectest forktest0 forktest1b
ALL += forktest1 forktest2b forktest2 forktest3 forkwait0c forkwait0p forkwait1b
ALL += forkwait1 forkwait1c forkwait1d init1 init2 init3 init shell trapillegal
ALL += trapmath trapmemory ttyread1 ttywrite1 ttywrite2 ttywrite3

PUBLIC_DIR = /clear/courses/comp421/pub

CPPFLAGS = -I$(PUBLIC_DIR)/include
CFLAGS = -g -Wall -Wextra

LANG = gcc

%: %.o
	$(LINK.o) -o $@ $^ $(LOADLIBES) $(LDLIBS)

LINK.o = $(PUBLIC_DIR)/bin/link-user-$(LANG) $(LDFLAGS) $(TARGET_ARCH)

%: %.c
%: %.cc
%: %.cpp

all: $(ALL)

clean:
	rm -f $(ALL)

