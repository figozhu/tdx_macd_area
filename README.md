# 通达信macd面积公式
使用效果：

![](https://github.com/figozhu/tdx_macd_area/blob/main/pic/demo.png)



导入DLL后，搭配通达信内公式源码：

```
DIF:=EMA(CLOSE,SHORT)-EMA(CLOSE,LONG);
DEA:=EMA(DIF,MID);
MACD:=(DIF-DEA)*2;

AREA:=TDXDLL1(1, MACD, 0, 0);

红面积:IF(AREA > 0, AREA, 0), NODRAW;
绿面积:IF(AREA < 0, AREA, 0), NODRAW;

STICKLINE(红面积, 0, 红面积, 3, 0),COLORRED;
STICKLINE(绿面积, 0, 绿面积, 3, 0),COLORGREEN;
```

