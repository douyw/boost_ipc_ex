//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2006-2012. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#include <boost/interprocess/detail/config_begin.hpp>
//[doc_managed_grow
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/managed_mapped_file.hpp>
#include <cassert>
//<-
#include "../test/get_process_id_name.hpp"
//->

//#define DOU_TEST_STRING_MEMBERS

class MyClass
{
    // [dou]
public:
    // case 0: char) max: 648
//    char m[648];
    // case 1: int32_t) max: 162, it failed after 163.
//    int32_t m[162];
    // case 1-1: int32_t) 10*int32_t = 40*bytes
//    int32_t m[10];
    // case 2: bool)         10*bool = 10*bytes
//    bool m[10];
    // case 3: string)     10*string = 240*bytes
#ifdef DOU_TEST_STRING_MEMBERS
    std::string m[10];
#endif
    // case 4: int64_t)   10*int64_t = 80*bytes
//    int64_t m[10];
    // case 5: bool(bit))  8*bit = 1*byte
    bool m1:1;
    bool m2:1;
    bool m3:1;
    bool m4:1;
    bool m5:1;
    bool m6:1;
    bool m7:1;
    bool m8:1;
    bool m9:1;
    // [uod]
};

#ifdef DOU_TEST_STRING_MEMBERS
void MyClass_init( MyClass& mc )
{
    for ( std::size_t i=0; i<10; ++i ) {
        mc.m[i] = "hello";
    }
}

void MyClass_dump( MyClass& mc )
{
    std::cout << "dump MyClass -->\n";
    for ( std::size_t i=0; i<10; ++i ) {
        std::cout << i << "\t" << mc.m[i] << "\n";
    }
    std::cout << "<-- MyClass dump\n";
}
#endif

int main()
{
   using namespace boost::interprocess;
   //Remove shared memory on construction and destruction
   struct shm_remove
   {
   //<-
   #if 1
      shm_remove() { shared_memory_object::remove(test::get_process_id_name()); }
      ~shm_remove(){ shared_memory_object::remove(test::get_process_id_name()); }
   #else
   //->
      shm_remove() { shared_memory_object::remove("MySharedMemory"); }
      ~shm_remove(){ shared_memory_object::remove("MySharedMemory"); }
   //<-
   #endif
   //->
   } remover;
   //<-
   (void)remover;
   //->

   // [dou]
   std::size_t size = sizeof(MyClass);
   std::cout << "MyClass size: " << size << std::endl;
   std::cout << "sizeof(std::string): " << sizeof(std::string) << std::endl;
#ifdef DOU_TEST_STRING_MEMBERS
   MyClass mc;
   MyClass_init(mc);
   std::cout << "MyClass instance size(10*string): " << sizeof(mc) << std::endl;
#endif
   // [uod]

   {
      //Create a managed shared memory
      //<-
      #if 1
      managed_shared_memory shm(create_only, test::get_process_id_name(), 1000);
      #else
      //->
      managed_shared_memory shm(create_only, "MySharedMemory", 1000);
      //<-
      #endif
      //->

      //Check size
      assert(shm.get_size() == 1000);
      //Construct a named object
      MyClass *myclass = shm.construct<MyClass>("MyClass")();
      //The managed segment is unmapped here
      //<-
      (void)myclass;
      //->
#ifdef DOU_TEST_STRING_MEMBERS
      MyClass_init(*myclass);
#endif
   }
   {
      //Now that the segment is not mapped grow it adding extra 500 bytes
      //<-
      #if 1
      managed_shared_memory::grow(test::get_process_id_name(), 500);
      #else
      //->
      managed_shared_memory::grow("MySharedMemory", 500);
      //<-
      #endif
      //->

      //Map it again
      //<-
      #if 1
      managed_shared_memory shm(open_only, test::get_process_id_name());
      #else
      //->
      managed_shared_memory shm(open_only, "MySharedMemory");
      //<-
      #endif
      //->
      //Check size
      assert(shm.get_size() == 1500);
      //Check "MyClass" is still there
      MyClass *myclass = shm.find<MyClass>("MyClass").first;
      assert(myclass != 0);
      //The managed segment is unmapped here
   }
   {
      //Now minimize the size of the segment
      //<-
      #if 1
      managed_shared_memory::shrink_to_fit(test::get_process_id_name());
      #else
      //->
      managed_shared_memory::shrink_to_fit("MySharedMemory");
      //<-
      #endif
      //->

      //Map it again
      //<-
      #if 1
      managed_shared_memory shm(open_only, test::get_process_id_name());
      #else
      //->
      managed_shared_memory shm(open_only, "MySharedMemory");
      //<-
      #endif
      //->
      //Check size
      assert(shm.get_size() < 1000);
      //Check "MyClass" is still there
      MyClass *myclass = shm.find<MyClass>("MyClass").first;
      assert(myclass != 0);
      //The managed segment is unmapped here
#ifdef DOU_TEST_STRING_MEMBERS
      MyClass_dump(*myclass);
#endif
   }
   return 0;
}
//]
#include <boost/interprocess/detail/config_end.hpp>
