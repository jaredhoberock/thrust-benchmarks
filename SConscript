import os

Import('env')

# create a clone of the environment so that we don't alter the parent
my_env = env.Clone()

# find all .cus & .cpps in the current directory
sources = []
directories = ['.']

# find all .cus & .cpps in the current directory
sources = []
directories = ['.']
extensions = ['.cu','.cpp']

for dir in directories:
  for ext in extensions:
    regex = os.path.join(dir, '*' + ext)
    sources.extend(my_env.Glob(regex))

# build the program
program = my_env.Program(sources)

