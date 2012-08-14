import os
import inspect

vars = Variables()
vars.Add(PathVariable('thrust_path', 'Path to thrust', os.path.dirname(os.path.abspath('.'))))

# try to import an environment first
try:
  Import('env')
except:
  exec open("../build/build-env.py")
  env = Environment(variables = vars)

env.Prepend(CPPPATH = [env['thrust_path']])

# on mac we have to tell the linker to link against the C++ library
if env['PLATFORM'] == "darwin":
  env.Append(LINKFLAGS = "-lstdc++")

# on windows we have to do /bigobj
if env['PLATFORM'] == "win32" or env['PLATFORM'] == "win64":
  env.Append(CPPFLAGS = "/bigobj")

# find all .cus & .cpps in the current and backend/ directories
sources = []
directories = ['.']
extensions = ['*.cu', '*.cpp']

for dir in directories:
  for ext in extensions:
    regexp = os.path.join(dir, ext)
    sources.extend(env.Glob(regexp))

# filter test files using a regular expression
if 'tests' in env:
  import re

  pattern = re.compile(env['tests'])

  necessary_sources = set(['testframework.cu'])
  filtered_sources  = []

  for f in sources:
    if str(f) in necessary_sources or pattern.search(f.get_contents()):
      filtered_sources.append(f)

  sources = filtered_sources

env.Append(CPPPATH = ['.','../testing'])

tester = env.Program('tester', sources)

