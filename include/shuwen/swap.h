struct swap_info_struct{//交换设备(硬盘)物理页面在内存中的数据结构
signed short prio; // 交换的优先级
unsigned int pages; //所有可用的交换页面
unsigned int inuse_pages;// 当前正在被使用的页面
};
