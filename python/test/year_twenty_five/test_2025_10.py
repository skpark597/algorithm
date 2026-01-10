import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

from common.tree_node import TreeNode
import year_twenty_five.october.connecting_cities_with_minimum_cost as minumum_cost
import year_twenty_five.october.find_the_safest_path_in_a_grid as maximum_safeness_factor
import year_twenty_five.october.regions_cut_by_slashes as regions_by_slashes
import year_twenty_five.october.wiggle_sort as wiggle_sort
import year_twenty_five.october.out_of_boundary_paths as find_paths
import year_twenty_five.october.two_sum_bsts as two_sum_bsts
import year_twenty_five.october.find_k_closest_elements as find_closest_elements
import year_twenty_five.october.minimum_operations_to_make_the_integer_zero as make_the_integer_zero
import year_twenty_five.october.palindrome_permutation_ii as generate_palindromes
import year_twenty_five.october.dot_product_of_two_sparse_vectors as dot_product
import year_twenty_five.october.missing_element_in_sorted_array as missing_element
import year_twenty_five.october.minimum_subarrays_in_a_valid_split as valid_subarray_split


def test_minimum_cost():
    solution = minumum_cost.Solution()

    n0 = 3
    connections0 = [[1, 2, 5], [1, 3, 6], [2, 3, 1]]

    n1 = 4
    connections1 = [[1, 2, 3], [3, 4, 4]]

    ret0 = solution.minimum_cost(n0, connections0)
    ret1 = solution.minimum_cost(n1, connections1)

    assert ret0 == 6
    assert ret1 == -1


def test_maximum_safeness_factor():
    solution = maximum_safeness_factor.Solution()

    grid0 = [[1, 0, 0], [0, 0, 0], [0, 0, 1]]
    grid1 = [[0, 0, 1], [0, 0, 0], [0, 0, 0]]
    grid2 = [[0, 0, 0, 1], [0, 0, 0, 0], [0, 0, 0, 0], [1, 0, 0, 0]]
    grid3 = [[1, 1, 1], [0, 1, 1], [0, 0, 0]]

    ret0 = solution.maximum_safeness_factor(grid0)
    ret1 = solution.maximum_safeness_factor(grid1)
    ret2 = solution.maximum_safeness_factor(grid2)
    ret3 = solution.maximum_safeness_factor(grid3)

    assert ret0 == 0
    assert ret1 == 2
    assert ret2 == 2
    assert ret3 == 0


def test_regions_by_slashes():
    solution = regions_by_slashes.Solution()

    grid0 = [" /", "/ "]
    grid1 = [" /", "  "]
    grid2 = ["/\\", "\\/"]
    grid3 = [" / ", " \\/", " / "]
    grid4 = ["/\\/\\", "\\///", " \\//", "////"]

    ret0 = solution.regions_by_slashes(grid0)
    ret1 = solution.regions_by_slashes(grid1)
    ret2 = solution.regions_by_slashes(grid2)
    ret3 = solution.regions_by_slashes(grid3)
    ret4 = solution.regions_by_slashes(grid4)

    assert ret0 == 2
    assert ret1 == 1
    assert ret2 == 5
    assert ret3 == 3
    assert ret4 == 9


def test_wiggle_sort():
    solution = wiggle_sort.Solution()

    nums0 = [3, 5, 2, 1, 6, 4]
    nums1 = [6, 6, 5, 6, 3, 8]

    solution.wiggle_sort(nums0)
    solution.wiggle_sort(nums1)

    assert nums0 == [3, 5, 1, 6, 2, 4]
    assert nums1 == [6, 6, 5, 6, 3, 8]


def test_find_paths():
    solution = find_paths.Solution()

    ret0 = solution.find_paths(2, 2, 2, 0, 0)
    ret1 = solution.find_paths(1, 3, 3, 0, 1)
    ret2 = solution.find_paths(10, 10, 0, 5, 5)

    assert ret0 == 6
    assert ret1 == 12
    assert ret2 == 0


def test_two_sum_bsts():
    solution = two_sum_bsts.Solution()

    root01 = TreeNode.make([2, 1, 4])
    root02 = TreeNode.make([1, 0, 3])
    target0 = 5

    root11 = TreeNode.make([0, -10, 10])
    root12 = TreeNode.make([5, 1, 7, 0, 2])
    target1 = 18

    ret0 = solution.two_sum_bsts(root01, root02, target0)
    ret1 = solution.two_sum_bsts(root11, root12, target1)

    assert ret0 is True
    assert ret1 is False


def test_find_closest_elements():
    solution = find_closest_elements.Solution()

    arr0 = [1, 2, 3, 4, 5]
    k0 = 4
    x0 = 3

    arr1 = [1, 1, 2, 3, 4, 5]
    k1 = 4
    x1 = -1

    ret0 = solution.find_closest_elements(arr0, k0, x0)
    ret1 = solution.find_closest_elements(arr1, k1, x1)

    assert ret0 == [1, 2, 3, 4]
    assert ret1 == [1, 1, 2, 3]


def test_make_the_integer_zero():
    solution = make_the_integer_zero.Solution()

    num01, num02 = 3, -2
    num11, num12 = 5, 7

    ret0 = solution.make_the_integer_zero(num01, num02)
    ret1 = solution.make_the_integer_zero(num11, num12)

    assert ret0 == 3
    assert ret1 == -1


def test_generate_palindromes():
    solution = generate_palindromes.Solution()

    s0 = "aabb"
    s1 = "abc"
    s2 = "aabbc"

    ret0 = solution.generate_palindromes(s0)
    ret1 = solution.generate_palindromes(s1)
    ret2 = solution.generate_palindromes(s2)

    assert sorted(ret0) == ["abba", "baab"]
    assert sorted(ret1) == []
    assert sorted(ret2) == ["abcba", "bacab"]


def test_dot_product():
    nums01 = [1, 0, 0, 2, 3]
    nums02 = [0, 3, 0, 4, 0]

    vec01 = dot_product.SparseVector(nums01)
    vec02 = dot_product.SparseVector(nums02)
    ans0 = vec01.dot_product(vec02)

    nums11 = [0, 1, 0, 0, 0]
    nums12 = [0, 0, 0, 0, 2]

    vec11 = dot_product.SparseVector(nums11)
    vec12 = dot_product.SparseVector(nums12)
    ans1 = vec11.dot_product(vec12)

    nums21 = [0, 1, 0, 0, 2, 0, 0]
    nums22 = [1, 0, 0, 0, 3, 0, 4]

    vec21 = dot_product.SparseVector(nums21)
    vec22 = dot_product.SparseVector(nums22)
    ans2 = vec21.dot_product(vec22)

    assert ans0 == 8
    assert ans1 == 0
    assert ans2 == 6


def test_missing_element():
    solution = missing_element.Solution()

    nums0, k0 = [4, 7, 9, 10], 1
    nums1, k1 = [4, 7, 9, 10], 3
    nums2, k2 = [1, 2, 4], 3

    ret0 = solution.missing_element(nums0, k0)
    ret1 = solution.missing_element(nums1, k1)
    ret2 = solution.missing_element(nums2, k2)

    assert ret0 == 5
    assert ret1 == 8
    assert ret2 == 6


def test_valid_subarray_split():
    solution = valid_subarray_split.Solution()

    nums0 = [2, 6, 3, 4, 3]
    nums1 = [3, 5]
    nums2 = [1, 2, 1]

    ret0 = solution.valid_subarray_split(nums0)
    ret1 = solution.valid_subarray_split(nums1)
    ret2 = solution.valid_subarray_split(nums2)

    assert ret0 == 2
    assert ret1 == 2
    assert ret2 == -1
