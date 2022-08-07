#include <iostream>
#include <vector>
#include <algorithm>

const std::vector<std::ptrdiff_t> ref_string { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3,
                                               0, 3, 2, 1, 2, 0, 1, 7, 0, 1 };

void
print_page_stack(std::vector<std::ptrdiff_t> page_stack) {
   for ( std::size_t i = 0; i < page_stack.size(); i++ ) {
      if ( page_stack.at(i) != (-1) ) {
         std::cout << page_stack.at(i) << " ";
      }
   }

   std::cout << std::endl;
}

std::ptrdiff_t
seek_index(std::vector<std::ptrdiff_t> list, std::size_t element) {
   std::vector<std::ptrdiff_t>::iterator itr =
      std::find_if(list.begin(), list.end(), [&](const std::size_t& value) {
         return (value == element);
      });

   return (itr != list.cend()) ? std::distance(list.begin(), itr)
                               : (std::ptrdiff_t)(-1);
}

std::size_t
fifo(std::size_t frames, std::vector<std::ptrdiff_t> ref_string) {
   std::size_t faults        = 0;
   std::size_t replace_count = 0;

   std::vector<std::ptrdiff_t> page_stack;

   for ( std::size_t i = 0; i < frames; i++ ) {
      page_stack.push_back(-1);
   }

   for ( std::size_t i = 0; i < ref_string.size(); i++ ) {
      if ( ! (std::count(page_stack.begin(), page_stack.end(),
                         ref_string.at(i))) ) {
         faults++;

         if ( std::count(page_stack.begin(), page_stack.end(), -1) ) {
            page_stack[seek_index(page_stack, -1)] = ref_string.at(i);
         } else {
            page_stack[replace_count] = ref_string[i];
            replace_count             = (replace_count + 1) % frames;
         }
      }
   }

   return faults;
}

int
main(void) {
   std::cout << "Reference String: ";

   for ( std::size_t i = 0; i < ref_string.size(); i++ ) {
      std::cout << ref_string.at(i) << " ";
   }

   std::cout << std::endl;

   for ( std::size_t i = 1; i < ref_string.size(); i++ ) {
      std::cout << "Faults caused by " << i
                << " frames: " << fifo(i, ref_string) << std::endl;
   }

   return 0;
}
