import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_four.jun.video_stitching as video_stitching


def test_video_stitching():
    solution0 = video_stitching.Solution()
    solution1 = video_stitching.Solution()
    solution2 = video_stitching.Solution()
    solution3 = video_stitching.Solution()
    solution4 = video_stitching.Solution()

    clips0, time0 = [[0, 2], [4, 6], [8, 10], [1, 9], [1, 5], [5, 9]], 10
    clips1, time1 = [[0, 1], [1, 2]], 5
    clips2, time2 = (
        [
            [0, 1],
            [6, 8],
            [0, 2],
            [5, 6],
            [0, 4],
            [0, 3],
            [6, 7],
            [1, 3],
            [4, 7],
            [1, 4],
            [2, 5],
            [2, 6],
            [3, 4],
            [4, 5],
            [5, 7],
            [6, 9],
        ],
        9,
    )
    clips3, time3 = [[0, 4], [2, 8]], 5
    clips4, time4 = (
        [[5, 7], [1, 8], [0, 0], [2, 3], [4, 5], [0, 6], [5, 10], [7, 10]],
        5,
    )

    result0 = solution0.video_stitching(clips0, time0)
    result1 = solution1.video_stitching(clips1, time1)
    result2 = solution2.video_stitching(clips2, time2)
    result3 = solution3.video_stitching(clips3, time3)
    result4 = solution4.video_stitching(clips4, time4)

    assert result0 == 3
    assert result1 == -1
    assert result2 == 3
    assert result3 == 2
    assert result4 == 1
