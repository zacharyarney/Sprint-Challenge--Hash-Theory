import unittest
from ex1 import get_indices_of_item_weights

class Test(unittest.TestCase):
  def test_correctness(self):
    self.assertEqual(get_indices_of_item_weights([9], 9), ())
    self.assertEqual(get_indices_of_item_weights([4, 4], 8), (1, 0))
    self.assertEqual(get_indices_of_item_weights([4, 6, 10, 15, 16], 21), (3, 1))
    self.assertEqual(get_indices_of_item_weights([12, 6, 7, 14, 19, 3, 0, 25, 40], 7), (6, 2))

if __name__ == '__main__':
  unittest.main()