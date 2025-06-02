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
        Medium/2929_Distribute_Candies_Among_Children_II/Solution.cpp)