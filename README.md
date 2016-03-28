## USING THESE TEST FILES

You can make the binaries that Yalnix uses by typing 'make' in the root
directory of this project (where this README lives)

Those binaries can then be run by your kernel by supplying their full paths as
the program argument to Yalnix.

Example:

`$ ./yalnix -lu 5 -lk 5 ~/KernelTest/cdb6_sls13/test_fork`

To see what the expected behavior of each of the test files is, look for a block
comment at the top of the source file.

You can also copy your `yalnix` binary into the directory that has the tests that
you want to run. This works well for anything that Exec's another program (like a
lot of the provided tests).

Example:

`cp /path/to/yalnix /path/to/KernelTest/provided`
`cd /path/to/KernelTest/provided`
`./yalnix testfile`

## CONTRIBUTING

To contribute your own test files, first create a directory for them that is
namespaced to you/your partner's netID's so that we don't have issues with file
names colliding.

Then, put all the test source files in there, along with a Makefile to compile
them (you can see the Makefile in cdb6_sls13 and use it as an example, you
should just have to modify the `ALL` field).

Put the name of this namespaced directory at the end of the DIRS variable at the
top of the Makefile.

Test it out! Make sure running `make` creates the binaries for all your test
files, and that `make clean` removes them.

Submit a Pull Request on GitHub so other people can benefit from your tests (even 
if you don't think they're good! Any additional information is good information).


