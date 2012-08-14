#!/usr/bin/env python

def make_report_dict(lines):
  import re
  result = {}

  for line in lines:
    # split on commas and whitespace
    test_and_time = line.split(',')
    (test,time) = (test_and_time[0], test_and_time[1])
    result[test] = time

  return result


def collate(filenames):
  names = []
  result = {}
  for filename in filenames:
    name = filename.split('.')[0]
    report = make_report_dict(open(filename).readlines())

    try:
      names.append(name)
    except:
      names = [name]
        
    for (test,time) in report.items():
      try:
        result[test].append(time)
      except:
        result[test] = [time]
  return (names, result)


def print_comma_separated(collated):
  (names, timing) = collated
  print "test,",
  for name in names:
    print "%s," % name,
  # newline
  print

  for (test, times) in sorted(timing.items()):
    print "%s," % test,
    for time in times:
      print "%s," % time,
  # newline
    print


if __name__ == "__main__":
  import sys
  print_comma_separated(collate(sys.argv[1:]))

