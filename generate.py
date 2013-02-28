#!/usr/bin/env python
from subprocess import check_call
import collate


def generate(datasizes):
  filenames = []
  for size in datasizes:
    print "Testing", size, "..."
    filename = "test_" + str(size) + ".txt"
    filenames.append(filename)
    f = open(filename, 'w')
    check_call(["./targets/cpp_host_cuda_device_release/driver", str(size)], stdout = f)
    f.close()

  collate.print_comma_separated(collate.collate(filenames))


if __name__ == "__main__":
  datasizes = [2**i for i in range(10,25)]
  generate(datasizes)

