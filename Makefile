DIRS = cdb6_sls13

all:
	$(foreach dir, $(DIRS), cd $(dir); make;)

clean:
	$(foreach dir, $(DIRS), cd $(dir); make clean;)
