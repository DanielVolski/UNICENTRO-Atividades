import sys, os, unittest

#This is to aceess parent directory and import Graph.py module
current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
sys.path.append(parent)

from Graph import Node, NodeState
from math import inf

class TestNode(unittest.TestCase):
    def test_init(self):
        node = Node('1')
        self.assertEqual(node.name, '1')
        self.assertEqual(node.distance, inf)
        self.assertEqual(node.parent, None)
        self.assertEqual(node.state, NodeState.UNKNOWN)

    def test_repr(self):
        node = Node(1)
        self.assertEqual(repr(node), 'Node("1", inf, None, "UNKNOWN")')
        self.assertEqual(str(node), '1')
    
    def test_eq(self):
        self.assertTrue(Node('1') == Node('1'), "The nodes doesnt have the same name")
        self.assertTrue(Node('a') == Node('a'), "The nodes doesnt have the same name")
        self.assertTrue(Node('bc') == Node('bc'), "The nodes doesnt have the same name")

if __name__ == '__main__':
    unittest.main()