from transitionMaps import *
import unittest
class partitionOfUnity(unittest.TestCase):
    def Test_transition(self):
        self.assertEqual(1,simplify(transition(x,y)))
partitionOfUnity().Test_transition()        
        
if __name__=='__main__':
    unittest.main()