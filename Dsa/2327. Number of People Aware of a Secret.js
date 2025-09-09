// On day 1, one person discovers a secret.

// You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

// Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.

/**
 * @param {number} n
 * @param {number} delay
 * @param {number} forget
 * @return {number}
 */
const peopleAwareOfSecret = (n, delay, forget) => {
    const dp = new Array(n + 1).fill(0);
    dp[1] = 1;
    let share = 0n;
    const MOD = 1000000007n;

    for (let t = 2; t <= n; t++) {
        if (t - delay > 0) share = (share + BigInt(dp[t - delay]) + MOD) % MOD;
        if (t - forget > 0) share = (share - BigInt(dp[t - forget]) + MOD) % MOD;
        dp[t] = Number(share);
    }

    let know = 0n;
    for (let i = n - forget + 1; i <= n; i++) know = (know + BigInt(dp[i])) % MOD;
    return Number(know);
}