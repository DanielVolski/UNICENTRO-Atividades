import sys, os, unittest

#This is to aceess parent directory and import Graph.py module
current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
sys.path.append(parent)

from Graph import Edge, Node
from math import inf

class TestEdge(unittest.TestCase):
    def test_init(self):
        start = Node('1')
        end = Node('2')
        edge = Edge(start, end)
        self.assertEqual(edge.start, start)
        self.assertEqual(edge.end, end)
        self.assertEqual(edge.weight, 1)

    def test_repr(self):
        start = Node('1')
        end = Node('2')
        edge = Edge(start, end)
        self.assertEqual(repr(edge), 'Edge(1, 2, 1)')
        self.assertEqual(str(edge), '(1, 2, 1)')
        
if __name__ == '__main__':
    unittest.main()