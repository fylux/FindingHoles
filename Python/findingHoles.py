def is_hole(matrix, p):
    for i in range(len(matrix)):
        if matrix[i][p] == 0 and i != p:
            return False
        if matrix[p][i] == 1:
            return False
    return True


def find_holes(matrix):
    # x and y are the two candidate nodes
    x, y = 0, 1
    # n is the # of nodes in our matrix
    n = len(matrix)

    # You're passing in an empty matrix
    if not n:
        return

    while y < n and x < n:
        # For each iteration, there are three cases that are checked here:
        # 1. They share an edge
        # 2. They have no edge
        # 3. One of them has an edge
        #
        # The first if statement catches case 1 and 2, in which case we ditch both
        # candidates and move on.
        # The second and third if statement catch each direction of case 3, in which case
        # we ditch the candidate being pointed to unidirectionally.

        # bidirectional edge, ditch both
        if matrix[x][y] and matrix[y][x] or not matrix[x][y] and not matrix[y][x]:
            x = max(x, y) + 1
            y = x + 1
        # x points to y so maybe y is a hole, since y points to x, x isn't
        elif matrix[x][y] and not matrix[y][x]:
            x = max(x, y) + 1
        # y points to x so maybe x us a hole, since x points to y, y isn't
        elif not matrix[x][y] and matrix[y][x]:
            y = max(x, y) + 1

    # Now check both. If they are >= n, it means no candidates were found. So for all those
    # that weren't, just check all edges to them in the matrix (a linear scan) to see if they are
    if x < n and is_hole(matrix, x):
        return x

    if y < n and is_hole(matrix, y):
        return y


def main():
    matrix = [[0, 0, 0, 0],
              [1, 0, 1, 0],
              [1, 0, 0, 1],
              [1, 0, 0, 0]]
    hole = find_holes(matrix)
    if hole is not None:
        print("Hole at node {}".format(hole))


if __name__ == "__main__":
    main()