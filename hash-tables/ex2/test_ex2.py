import unittest
from ex2 import reconstruct_trip

class Test(unittest.TestCase):
  def test_short_case(self):
    short_set = [
      (None, 'PDX'),
      ('PDX', 'DCA'),
      ('DCA', None)
    ]
    self.assertEqual(reconstruct_trip(short_set), ['PDX', 'DCA'])

  def test_long_case(self):
    long_set = [
      ('PIT', 'ORD'),
      ('XNA', 'CID'),
      ('SFO', 'BHM'),
      ('FLG', 'XNA'),
      (None, 'LAX'), 
      ('LAX', 'SFO'),
      ('CID', 'SLC'),
      ('ORD', None),
      ('SLC', 'PIT'),
      ('BHM', 'FLG'),
    ]
    self.assertEqual(reconstruct_trip(long_set), ['LAX', 'SFO', 'BHM', 'FLG', 'XNA', 'CID', 'SLC', 'PIT', 'ORD'])

  def test_incorrect_case(self):
    incorrect_set = [
      ('LHD', 'DAB'),
      (None, 'HVN'),
      ('MSO', 'SFO'),
      ('RDU', 'ABQ'),
      ('ACY', None),
    ]
    self.assertEqual(reconstruct_trip(incorrect_set), [])

if __name__ == '__main__':
  unittest.main()