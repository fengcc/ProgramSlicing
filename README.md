# Static Program Slicing Tool Of Backward Slice 

This is a simple program slicing tool in C and also for C programs to see depending lines of code.

## Usage
Clone the code:
```bash
git clone https://github.com/feng01/ProgramSlicing.git
```
#### If you just want to run it:
```bash
cd ProgramSlicing
./ProgramSlicing filepath/test.c	#the second parameter is the code you want to analysis
```
Then input the slicing criterion : line number and variables.</br>
The slice result will saved in the file named test_slice.c which is located in the same directory as test.c.

#### If you want to modify the code and recompile it:
First， some software you need install:
* flex
* bison
* graphviz</br>

On OpenSuse,you can use following command to install them:
```bash
sudo zypper install flex bison graphviz
```
Then, run `make` to recompile the code you have modified.


## Bugs
The program doesn't support all of the C syntax，and need to further improve.</br>
For example:
* fuction call doesn's support.
* Pointer does's support.
* You should use `i=i+1` instead of `i++`.

and so on.
