def readData():
    fileName = input("Enter the data file name: ")

    with open(fileName) as file:
        lines = file.readlines()

    file.close()

    lines = [line.strip() for line in lines]

    print("Data file has", len(lines), "items")

    return lines


if __name__ == "__main__":
    data = readData()

    choice = input("Select solution to run: part 1 or part 2? (1/2): ").strip()
    RUN_PART1 = choice == "1"

    rollsCount = 0
    rollsPositions = ["Empty"]

    rows = len(data)
    cols = len(data[0])
    print(f"The line is {cols} columns long")

    # Parse each line
    while True:
        if len(rollsPositions) == 0:
            break

        rollsPositions = []

        for i in range(len(data)):
            print("Row:", i)
            # Parse each column
            for j in range(len(data[i])):
                print("Column:", j)
                surroundings = 0

                if (data[i])[j] == "@":
                    if (i - 1) >= 0 and (j - 1) >= 0 and (data[i - 1])[j - 1] == "@":
                        surroundings += 1
                    if (i - 1) >= 0 and (data[i - 1])[j] == "@":
                        surroundings += 1
                    if (i - 1) >= 0 and (j + 1) < cols and (data[i - 1])[j + 1] == "@":
                        surroundings += 1

                    if (j - 1) >= 0 and (data[i])[j - 1] == "@":
                        surroundings += 1
                    if (j + 1) < cols and (data[i])[j + 1] == "@":
                        surroundings += 1

                    if (i + 1) < rows and (j - 1) >= 0 and (data[i + 1])[j - 1] == "@":
                        surroundings += 1
                    if (i + 1) < rows and (data[i + 1])[j] == "@":
                        surroundings += 1
                    if (
                        (i + 1) < rows
                        and (j + 1) < cols
                        and (data[i + 1])[j + 1] == "@"
                    ):
                        surroundings += 1

                    if surroundings < 4:
                        rollsCount += 1
                        rollsPositions.append((i, j))

                        if not RUN_PART1:
                            row = list(data[i])
                            row[j] = "."
                            data[i] = "".join(row)

            if RUN_PART1:
                rollsPositions = []

    print(f"Number of rolls that can be moved by forklift: {rollsCount}")
