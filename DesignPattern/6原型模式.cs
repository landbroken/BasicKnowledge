using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DesignPattern.Prototype
{
    #region 教程

    ///火影忍者中鸣人的影分身和孙悟空的的变都是原型模式
    public class Client
    {
        public static void test()
        {
            // 孙悟空 原型
            MonkeyKingPrototype prototypeMonkeyKing = new ConcretePrototype("MonkeyKing");
            Console.WriteLine("Prototype:\t" + prototypeMonkeyKing.Id);

            // 变一个
            MonkeyKingPrototype cloneMonkeyKing = prototypeMonkeyKing.Clone() as ConcretePrototype;
            Console.WriteLine("Cloned1:\t" + cloneMonkeyKing.Id);

            // 变两个
            MonkeyKingPrototype cloneMonkeyKing2 = prototypeMonkeyKing.Clone() as ConcretePrototype;
            Console.WriteLine("Cloned2:\t" + cloneMonkeyKing2.Id);
            Console.ReadLine();
        }
    }

    /// <summary>
    /// 孙悟空原型
    /// </summary>
    public abstract class MonkeyKingPrototype
    {
        public string Id { get; set; }
        public MonkeyKingPrototype(string id)
        {
            this.Id = id;
        }

        // 克隆方法，即孙大圣说“变”
        public abstract MonkeyKingPrototype Clone();
    }

    /// <summary>
    /// 创建具体原型
    /// </summary>
    public class ConcretePrototype : MonkeyKingPrototype
    {
        public ConcretePrototype(string id)
            : base(id)
        { }

        /// <summary>
        /// 浅拷贝
        /// </summary>
        /// <returns></returns>
        public override MonkeyKingPrototype Clone()
        {
            // 调用MemberwiseClone方法实现的是浅拷贝，另外还有深拷贝
            return (MonkeyKingPrototype)this.MemberwiseClone();
        }
    }

    #endregion

    #region 自己写的

    public class MyClient
    {
        public static void test()
        {
            string tmp = "";

            // 原型
            PersonPrototype prototypePerson = new Male(nameof(Male),18);
            tmp = $"Prototype Age={prototypePerson.Age},Id={prototypePerson.Id}";
            Console.WriteLine(tmp);

            // 第一个
            PersonPrototype cloneMale = prototypePerson.Clone() as Male;
            //浅拷贝，字段是值类型的，则对字段执行逐位复制，
            //如果字段是引用类型的，则复制对象的引用，而不复制对象，
            //因此：原始对象和其副本引用同一个对象！
            //Age是值类型
            cloneMale.Age = 20;
            tmp = $"Prototype Age={prototypePerson.Age},Id={prototypePerson.Id}";
            Console.WriteLine(tmp);
            tmp = $"cloneMale Age={cloneMale.Age},Id={cloneMale.Id}";
            Console.WriteLine(tmp);

            // 第二个
            PersonPrototype cloneMale2 = prototypePerson.Clone() as Male;
            cloneMale2.Age = 22;
            tmp = $"Prototype Age={prototypePerson.Age},Id={prototypePerson.Id}";
            Console.WriteLine(tmp);
            tmp = $"cloneMale2 Age={cloneMale2.Age},Id={cloneMale2.Id}";
            Console.WriteLine(tmp);
            Console.ReadLine();
        }
    }

    /// <summary>
    /// 原型
    /// </summary>
    public abstract class PersonPrototype
    {
        public int Age { get; set; } = 0;
        public string Id { get; set; }
        public PersonPrototype(string id, int age)
        {
            this.Age = age;
            this.Id = id;
        }

        // 克隆方法
        public abstract PersonPrototype Clone();
    }

    /// <summary>
    /// 创建具体原型
    /// </summary>
    public class Male : PersonPrototype
    {
        public Male(string id, int age)
            : base(id, age)
        { }

        /// <summary>
        /// 浅拷贝
        /// </summary>
        /// <returns></returns>
        public override PersonPrototype Clone()
        {
            // 调用MemberwiseClone方法实现的是浅拷贝，另外还有深拷贝
            return (PersonPrototype)this.MemberwiseClone();
        }
    }

    ///原型在new的时候已经变成male类型了，不能拷贝为female类
    ///// <summary>
    ///// 创建具体原型
    ///// </summary>
    //public class Female : PersonPrototype
    //{
    //    public Female(string id, int age)
    //        : base(id, age)
    //    { }

    //    /// <summary>
    //    /// 浅拷贝
    //    /// </summary>
    //    /// <returns></returns>
    //    public override PersonPrototype Clone()
    //    {
    //        // 调用MemberwiseClone方法实现的是浅拷贝，另外还有深拷贝
    //        var ret = (PersonPrototype)this.MemberwiseClone();
    //        return ret;
    //    }
    //}

    #endregion
}
