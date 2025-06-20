cmake_minimum_required(VERSION 3.25)
project(Leetcode)

set(CMAKE_CXX_STANDARD 17)

# Recursively collect all .cpp files in the project
file(GLOB_RECURSE ALL_SOURCE_FILES
        "Hard/*.cpp"
        "Medium/*.cpp"
        "Easy/*.cpp"
        "Algorithms/*.cpp"
)

add_executable(Leetcode ${ALL_SOURCE_FILES}
        Medium/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal/solution.cpp
        Medium/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal/optimization.cpp
        "Hard/149_Max_Points_on_a _Line/solution.cpp"
        Easy/993_Cousins_in_Binary_Tree/solution.cpp
        Medium/199_Binary_Tree_Right_Side_View/solution.cpp
        Medium/199_Binary_Tree_Right_Side_View/optimized.cpp
        Medium/988_Smallest_String_Starting_From_Leaf/solution.cpp
        Medium/1448_Count_Good_Nodes_in_Binary_Tree/solution.cpp
        Medium/1161_Maximum_Level_Sum_of_a_Binary_Tree/solution.cpp
        Medium/1161_Maximum_Level_Sum_of_a_Binary_Tree/optimized.cpp
        Medium/700_Search_in_a_Binary_Search_Tree/solution.cpp
        Algorithms/Tree/serialization_and_deserialization.cpp
        Hard/297_Serialize_and_Deserialize_Binary_Tree/solution.cpp
        Medium/1302_Deepest_Leaves_Sum/solution.cpp
        Hard/297_Serialize_and_Deserialize_Binary_Tree/optimized.cpp
        Medium/1302_Deepest_Leaves_Sum/optimized.cpp
        Medium/103_Binary_Tree_Zigzag_Level_Order_Traversal/solution.cpp
        Medium/98_Validate_Binary_Search_Tree/solution.cpp
        Medium/99_Recover_Binary_Search_Tree/solution.cpp
        Algorithms/Tree/Morris_Inorder_traversal.cpp
        Easy/144_Binary_Tree_Preorder_Traversal/Solution.cpp
        Easy/145_Binary_Tree_Postorder_Traversal/Solution.cpp
        Medium/102_Binary_Tree_Level_Order_Traversal/Solution.cpp
        Medium/107_Binary_Tree_Level_Order_Traversal_II/Solution.cpp
        Medium/236_Lowest_Common_Ancestor_of_a_Binary_Tree/Solution.cpp
        Algorithms/Tree/Ancestors_of_node.cpp
        Hard/135_Candy/Solution.cpp
        Medium/2929_Distribute_Candies_Among_Children_II/Solution.cpp
        Medium/1372_Longest_ZigZag_Path_in_a_Binary_Tree/Solution.cpp
        Medium/2096_Step_By_Step_Directions_From_a_Binary_Tree_Node_to_Another/Solution.cpp
        Medium/2434_Using_a_Robot_to_Print_the_Lexicographically_Smallest_String/Solution.cpp
        Medium/3170_Lexicographically_Minimum_String_After_Removing_Stars/Solution.cpp
        Medium/124_Binary_Tree_Maximum_Path_Sum/Solution.cpp
        Medium/386_Lexicographical_Numbers/Solution.cpp
        Medium/386_Lexicographical_Numbers/Optimize.cpp
        Medium/7_Reverse_Integer/Solution.cpp
        Medium/15_3Sum/Solution.cpp
        Medium/84_Largest_Rectangle_in_Histogram/Solution.cpp
        Hard/440_K_th_Smallest_in_Lexicographical_Order/Solution.cpp
        Hard/440_K_th_Smallest_in_Lexicographical_Order/Optimized.cpp
        Algorithms/Tree/Lexographical_Tree.cpp
        Easy/3442_Maximum_Difference_Between_Even_and_Odd_Frequency_I/Solution.cpp
        Hard/3445_Maximum_Difference_Between_Even_and_Odd_Frequency_II/Solution.cpp
        Hard/3423_Maximu_Difference_Between_Adjacent_Elements_in_a_Circular_Array/Solution.cpp
        Medium/19_Remove_Nth_Node_From_End_of_List/Solution.cpp
        Medium/86_Partition_List/Solution.cpp
        Easy/2566_Maximum_Difference_by_Remapping_a_Digit/Solution.cpp
        Easy/2016_Maximum_Difference_Between_Increasing_Elements/Solution.cpp
        Hard/3405_count_the_number_of_arrays_with_k_matching_adjacent_elements/Solution.cpp
        Medium/2966_divide_array_into_arrays_with_max_difference/Solution.cpp
        Medium/15_3Sum/Optimized.cpp
        Medium/2294_partition_array_such_that_maximum_difference_is_k/Solution.cpp
        Easy/1_Two_sum/Solution.cpp
        Medium/658_Find_K_Closest_Elements/Solution.cpp
        Medium/3443_Maximum_Manhattan_Distance_After_K_Changes/Solution.cpp
)