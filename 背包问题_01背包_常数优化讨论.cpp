for i ← 1 to n
    for v ← V to max(w[i],V-(w[i] + w[i+1]+...+w[n]))

优化原理：dp[W]最终绝对不会被V-(w[i] + w[i+1] + ... + w[N])的数据所影响
因为我们只考虑旧数据

参考
https://www.edwardzcn98yx.com/post/1590e320.html

