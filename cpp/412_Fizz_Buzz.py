class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ret = [0] * n
        for i in range(1, n + 1):
            val = ""
            if i % 3 == 0: 
                if i % 5 == 0:
                    val = "FizzBuzz"
                else:
                    val = "Fizz"
            elif i % 5 == 0:
                val = "Buzz"
            else:
                val = str(i)

            ret[i - 1] = val

        return ret

