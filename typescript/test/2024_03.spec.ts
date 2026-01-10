import { minMoves2 } from "../2024_03/MinimumMovesToEqualArrayElementsII";

describe("2024_03 test", () => {
  it("minimum moves to equal array elements ii", () => {
    const nums0 = [1, 2, 3];
    const nums1 = [1, 10, 2, 9];

    const result0 = minMoves2(nums0);
    const result1 = minMoves2(nums1);

    expect(result0).toEqual(2);
    expect(result1).toEqual(16);
  });
});
