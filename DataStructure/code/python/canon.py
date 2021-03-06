line1 = [3, 3] # 双方的炮台数
line2 = [1, 1, 1] # 敌方的炮台血量
line3 = [1, 2, 3] # 我能选择的炮台血量

# 利用贪心的思想，要保证肯定能获胜利, 要让自己处于最不利的条件，敌方最好的条件
# 因为炮台是随机攻击的，如果血量为0，则不能攻击，
# 如果我方运气很差，每次所有炮台只攻击血量最高的
# 对方总是优先攻击我们血量最低的，这样都能保证胜利, 就是肯定能胜利
line2.sort() # 所以要将敌方方血量从小到大排序好
line3.sort(reverse=True) # 我方血量要从大到小排序好
enemy_count = line1[0] # 敌方的炮台数
res = 1 # 存储最后的答案, 先从第一台开始叠加
while (res < line1[1]): # 一直进行游戏，如果所有炮台都用到了还打不过，则游戏结束
    blood = sum(line3[:res]) # 统计我方炮台血量
    while (blood > 0): # 所有血量小于0，则失败
        # 首先我方开始攻击
        att_obj = -1 # 优先攻击敌方最右边血最多的那个
        my_can_count = res # 初始化我方炮台数，因为后面可能被消灭
        line2[att_obj] = line2[att_obj] - my_can_count # 最右边炮台血量要减去我方炮台数
        if (line2[att_obj] < 0): # 如果血量小于0 则攻击下一个
            att_obj -= 1vimspector#Continue()

        # 敌方开始攻击
        att_pos = -1 # 先攻击我方炮台血最少的那个
        line3[att_pos] -= abs(att_obj) # 我方血量减去敌方炮台数
        if (line3[att_pos] < 0): # 血量少于0， 则炮台数减1
            att_pos -= 1






    res += 1 # 失败则我方炮台数量加1





print(-1) # 失败输出-1



