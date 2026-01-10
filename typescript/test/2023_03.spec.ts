import { minimumCardPickup } from "../2023_03/MinimumConsecutiveCardsToPickUp";

describe("2023_03 test", () => {
  it("minimum consecutive cards to pick up", () => {
    const cards0 = [3, 4, 2, 3, 4, 7];
    const cards1 = [1, 0, 5, 3];
    const cards2 = [0, 0];

    const answer0 = 4;
    const answer1 = -1;
    const answer2 = 2;

    const result0 = minimumCardPickup(cards0);
    const result1 = minimumCardPickup(cards1);
    const result2 = minimumCardPickup(cards2);

    expect(result0).toEqual(answer0);
    expect(result1).toEqual(answer1);
    expect(result2).toEqual(answer2);
  });
});
