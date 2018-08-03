using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.算法
{
    public class MinStack
    {
        private readonly Stack<int> data = new Stack<int>();
        private readonly Stack<int> minValue = new Stack<int>();

        /** initialize your data structure here. */
        public MinStack()
        {

        }

        public void Push(int x)
        {
            data.Push(x);
            if (minValue.Count == 0 || x <= minValue.Peek())
                minValue.Push(x);
        }

        public void Pop()
        {
            int value = data.Pop();
            if (value == minValue.Peek())
                minValue.Pop();
        }

        public int Top()
        {
            return data.Peek();
        }

        public int GetMin()
        {
            return minValue.Peek();
        }
    }

    public class MinStackTest
    {
        static void test()
        {
            MinStack obj = new MinStack();
            obj.Push(5);
            obj.Pop();
            int param_3 = obj.Top();
            int param_4 = obj.GetMin();
        }
    }
}
