import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.may.lru_cache as lru_cache
import year_twenty_five.may.insert_delete_get_random_o1 as insert_delete_get_random_o1
import year_twenty_five.may.count_good_numbers as count_good_numbers
import year_twenty_five.may.letter_tile_possibilities as letter_tile_possibilities
import year_twenty_five.may.most_profit_assigning_work as most_profit_assignment
import year_twenty_five.may.stone_game as stone_game
import year_twenty_five.may.reveal_cards_in_increasing_order as reveal_cards


def test_lru_cache():
    cache = lru_cache.LRUCache(2)

    cache.put(1, 1)
    cache.put(2, 2)

    result0 = cache.get(1)
    assert result0 == 1

    cache.put(3, 3)

    result1 = cache.get(2)
    assert result1 == -1

    cache.put(4, 4)

    result2 = cache.get(1)
    result3 = cache.get(3)
    result4 = cache.get(4)

    assert result2 == -1
    assert result3 == 3
    assert result4 == 4

    cache = lru_cache.LRUCache(2)
    result0 = cache.get(2)
    assert result0 == -1

    cache.put(2, 6)

    result1 = cache.get(1)
    assert result1 == -1

    cache.put(1, 5)

    cache.put(1, 2)

    result2 = cache.get(1)
    assert result2 == 2

    result3 = cache.get(2)
    assert result3 == 6

    cache = lru_cache.LRUCache(1)
    cache.put(2, 1)

    result0 = cache.get(2)
    assert result0 == 1

    cache.put(3, 2)
    result1 = cache.get(2)
    assert result1 == -1

    result2 = cache.get(3)
    assert result2 == 2


def test_insert_delete_random_o1():
    solution = insert_delete_get_random_o1.RandomizedSet()

    result0 = solution.insert(0)
    result1 = solution.insert(1)
    result2 = solution.insert(1)

    result3 = solution.remove(0)
    result4 = solution.insert(2)
    result5 = solution.remove(1)
    result6 = solution.remove(1)

    result7 = solution.get_random()

    assert result0 is True
    assert result1 is True
    assert result2 is False

    assert result3 is True
    assert result4 is True
    assert result5 is True
    assert result6 is False

    assert result7 == 2


def test_count_good_numbers():
    solution = count_good_numbers.Solution()

    result0 = solution.count_good_numbers(1)
    result1 = solution.count_good_numbers(4)
    result2 = solution.count_good_numbers(50)

    assert result0 == 5
    assert result1 == 400
    assert result2 == 564908303


def test_letter_tile_possibilities():
    solution = letter_tile_possibilities.Solution()

    result0 = solution.num_tile_possibilities("AAB")
    result1 = solution.num_tile_possibilities("AAABBC")
    result2 = solution.num_tile_possibilities("V")

    assert result0 == 8
    assert result1 == 188
    assert result2 == 1


def test_most_profit_assignment():
    solution = most_profit_assignment.Solution()

    difficulties0 = [2, 4, 6, 8, 10]
    profits0 = [10, 20, 30, 40, 50]
    workers0 = [4, 5, 6, 7]

    difficulties1 = [85, 47, 57]
    profits1 = [24, 66, 99]
    workers1 = [40, 25, 25]

    difficulties2 = [68, 35, 52, 47, 86]
    profits2 = [67, 17, 1, 81, 3]
    workers2 = [92, 10, 85, 84, 82]

    difficulties3 = [17, 23, 25, 30, 30, 34, 55, 58, 72, 85]
    profits3 = [4, 41, 57, 64, 65, 68, 73, 73, 87, 98]
    workers3 = [99, 35, 21, 66, 22, 7, 12, 75, 8, 94]

    difficulties4 = [66, 1, 28, 73, 53, 35, 45, 60, 100, 44, 59, 94, 27, 88, 7, 18, 83, 18, 72, 63]
    profits4 = [66, 20, 84, 81, 56, 40, 37, 82, 53, 45, 43, 96, 67, 27, 12, 54, 98, 19, 47, 77]
    workers4 = [61, 33, 68, 38, 63, 45, 1, 10, 53, 23, 66, 70, 14, 51, 94, 18, 28, 78, 100, 16]

    result0 = solution.max_profit_assignment(difficulties0, profits0, workers0)
    result1 = solution.max_profit_assignment(difficulties1, profits1, workers1)
    result2 = solution.max_profit_assignment(difficulties2, profits2, workers2)
    result3 = solution.max_profit_assignment(difficulties3, profits3, workers3)
    result4 = solution.max_profit_assignment(difficulties4, profits4, workers4)

    assert result0 == 100
    assert result1 == 0
    assert result2 == 324
    assert result3 == 432
    assert result4 == 1392


def test_stone_game():
    solution = stone_game.Solution()

    piles0 = [5, 3, 4, 5]
    piles1 = [3, 7, 2, 3]

    result0 = solution.stone_game(piles0)
    result1 = solution.stone_game(piles1)

    assert result0 is True
    assert result1 is True


def test_reveal_cards():
    solution = reveal_cards.Solution()

    deck0 = [17, 13, 11, 2, 3, 5, 7]
    deck1 = [1, 1000]

    result0 = solution.deck_revealed_increasing(deck0)
    result1 = solution.deck_revealed_increasing(deck1)

    assert result0 == [2, 13, 3, 11, 5, 17, 7]
    assert result1 == [1, 1000]
