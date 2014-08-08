#!/usr/bin/env python
import sys
import os.path
from subprocess import check_call
import collate


def generate(path_to_driver, datasizes):
  filenames = []
  for size in datasizes:
    sys.stderr.write("Testing " + str(size) + "...\n")
    filename = str(size) + ".txt"
    filenames.append(filename)
    f = open(filename, 'w')
    check_call([path_to_driver, str(size)], stdout = f)
    f.close()

  collate.print_comma_separated(collate.collate(filenames))


if __name__ == "__main__":
  path_to_driver = "./targets/cpp_host_cuda_device_release/driver"
  if len(sys.argv) > 1:
      path_to_driver = str(sys.argv[1])
  path_to_driver = os.path.abspath(path_to_driver)
  datasizes = [2**i for i in range(10,25)]
  generate(path_to_driver, datasizes)

