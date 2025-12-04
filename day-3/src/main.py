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

    while True:
        NUM_BATTERY = input("Enter the number of batteries to turn on: ")

        if NUM_BATTERY.isdigit():
            NUM_BATTERY = int(NUM_BATTERY)
            break
        else:
            print("Please enter a valid number")

    joltages = []

    for bank in range(len(data)):

        currentLine = data[bank]

        print("Joltage Bank", bank, ":", currentLine, ".")

        if NUM_BATTERY > len(currentLine):
            print(
                f"String is only {len(currentLine)} chars long. Input length too high."
            )

        result = []
        start = 0

        for battery in range(NUM_BATTERY):
            # digits left to pick
            remaining = NUM_BATTERY - battery
            # Get the last index allowed to search
            maxSearchIndex = len(currentLine) - remaining

            if maxSearchIndex < start:
                maxSearchIndex = len(currentLine) - 1

            best = "0"
            bestPos = start

            # scan from current 'start' to allowed maximum
            for i in range(start, min(maxSearchIndex + 1, len(currentLine))):
                if currentLine[i] > best:
                    best = currentLine[i]
                    best_pos = i

            result.append(best)
            start = best_pos + 1

        resultStr = "".join(result)
        print("Result:", resultStr)

        joltages.append(int(resultStr))

    sum = 0
    for joltage in joltages:
        sum += joltage

    print("The sum of the joltages is:", sum)
