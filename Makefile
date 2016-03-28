DIRS = cdb6_sls13 aab15_bsw2 provided

all:
	-for d in $(DIRS); do (cd $$d; $(MAKE)); done

clean:
	-for d in $(DIRS); do (cd $$d; $(MAKE) clean); done
