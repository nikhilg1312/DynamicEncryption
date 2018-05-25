#include <linux/skbuff.h>
#include <linux/netfilter.h>
#include <linux/netdevice.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/mm.h>
#include <linux/err.h>
#include <linux/crypto.h>
#include <linux/init.h>
#include <linux/crypto.h>
#include <linux/scatterlist.h>
#include <net/ip.h>
#include <net/udp.h>
#include <net/route.h>

#undef __KERNEL__
#include <linux/netfilter_ipv4.h>
#define __KERNEL__

#define IP_HDR_LEN 20
#define UDP_HDR_LEN 8
#define TOT_HDR_LEN 28

static unsigned int pkt_mangle_begin(unsigned int hooknum,
                        struct sk_buff *skb,
                        const struct net_device *in,
                        const struct net_device *out,
                        int (*okfn)(struct sk_buff *));

static struct nf_hook_ops pkt_mangle_ops __read_mostly = {
    .pf = NFPROTO_IPV4,
    .priority = 1,
    .hooknum = NF_IP_LOCAL_OUT,
    .hook = pkt_mangle_begin,
};

static int __init pkt_mangle_init(void)
{
    printk(KERN_ALERT "\npkt_mangle module started ... :)");
    return nf_register_hook(&pkt_mangle_ops);
}

static void __exit pkt_mangle_exit(void)
{
    nf_unregister_hook(&pkt_mangle_ops);
    printk(KERN_ALERT "pkt_mangle module stopped ...");
} 

static unsigned int pkt_mangle_begin (unsigned int hooknum,
                        struct sk_buff *skb,
                        const struct net_device *in,
                        const struct net_device *out,
                        int (*okfn)(struct sk_buff *))
{ 

	
    struct iphdr *iph;
    struct udphdr *udph;
    struct tcphdr *tcph;
    unsigned char *data;

    unsigned int data_len;
    unsigned char extra_data[] = "12345";
    unsigned char *temp;
    unsigned int extra_data_len;
    unsigned int tot_data_len;
    unsigned char *temp1;	
    unsigned int i;
    unsigned int actual_data_length;
    __u16 dst_port, src_port;
    __u32 seq;

    int algo_no;
    
    if (skb) {
        iph = (struct iphdr *) skb_header_pointer (skb, 0, 0, NULL);

	
	if(iph && iph->protocol &&(iph->protocol == IPPROTO_TCP)){
	  printk(KERN_ALERT "GOT TCP OUTGOING");
	tcph = (struct tcphdr *)skb_header_pointer(skb,IP_HDR_LEN,0,NULL);
	seq = ntohs(tcph->seq);
	printk("%d",tcph->seq % 20 );
	
	printk("\n %pl4\n",tcph->seq);
	//data = (unsigned char *) skb_header_pointer (skb, IP_HDR_LEN+sizeof(struct tcphdr), 0, NULL);
	tcph = (struct tcphdr *)((__u32 *)iph + iph->ihl);
	
	data = (char *)((unsigned char *)tcph + (tcph->doff * 4));
	
	
	printk("\n\nDATA:%s",data);
	
	//printk("%u",ntohs(tcph->source));
	  
	}
        if (iph && iph->protocol &&(iph->protocol == IPPROTO_UDP)) {
            udph = (struct udphdr *) skb_header_pointer (skb, IP_HDR_LEN, 0, NULL);
            src_port = ntohs (udph->source);
            dst_port = ntohs (udph->dest);
  
		
		
            if (src_port == 43454) {
              
	      printk(KERN_ALERT "UDP packet goes out");
                data = (unsigned char *) skb_header_pointer (skb, IP_HDR_LEN+UDP_HDR_LEN, 0, NULL);
                data_len = skb->len - TOT_HDR_LEN;
		

		
		temp = kmalloc(512 * sizeof(char), GFP_ATOMIC);
		memcpy(temp, extra_data, sizeof(extra_data));

                unsigned char *ptr = data + data_len;//temp + sizeof(data);
		
		extra_data_len = sizeof(extra_data);
                memcpy(ptr, extra_data, extra_data_len);
		
		//printk(KERN_ALERT "\nPTR:%s",ptr);
                
		tot_data_len = data_len+extra_data_len ;

                skb_put(skb, extra_data_len - 1);
		
		
		
		memcpy(temp,data,data_len);
		printk("\nTEMP:%s",temp);
		
		ptr = &temp + data_len;
		
		memcpy(ptr,extra_data,extra_data_len);
		printk("\nPTR:%s",ptr);
		
		memcpy(data,temp,data_len+extra_data_len);
		printk("\nDATA:%s",data);
		
/*
		i=0;
		while(data[i]!='\0')
		 i++;
		data[i-1]='n';
		data[i]='\0';
		data_len++;
		*/
get_random_bytes(&algo_no,sizeof(algo_no));
algo_no = algo_no%5;

  
  switch(algo_no){
    case 0:
    case 1:

		for(i=0;i<data_len-2;i++)
		{
		  data[i]=data[i]^0x8A ;
		}
		
		printk("\nEncrypting Case 1 or 0");
break;

    case 2:
      for(i=0;i<data_len-2;i++)
		{
		  
		  data[i]=data[i]^0x9A ;
		}
		printk("\nEncrypting Case 2");
      break;
      
    case 3:
      
      for(i=0;i<data_len-2;i++)
		{
		  
		  data[i]=data[i]^0xAA ;
		}
		printk("\nEncrypting Case 3");
      break;
      
    case 4:
      
      for(i=0;i<data_len-2;i++)
		{
		  
		  data[i]=data[i]^0xBA ;
		}
		printk("\nEncrypting Case 4");
      break;
    
  }
  
  
		for(i=data_len;i>0;i--)
		{
		  data[i+1]=data[i];
		}
		data[1]=data[0];
		data_len++;
		
switch(algo_no){
  		
		
  case 0:
  case 1:
    data[0]='A';
	
  break;
  
  case 2:
    data[0]='B';
    break;
  case 3:
    data[0]='C';
    break;
    
  case 4:
    data[0]='D';
    break;
    
    
		
  }	
		
		
		
		
		
		
		
		
		
		
		
		
		

	


	
        //        printk(KERN_ALERT "%s",data);
		//memcpy(ptr, temp, tot_data_len);


	//	printk(KERN_ALERT "%s",temp);
		
               i=1;
//	 unsigned char *ptr=skb_push(skb,1);
//	  memcpy(ptr,&i,(unsigned int)1);
//	  data_len++;
	  
//	  printk(KERN_ALERT "Ethech zol aahe");
 /* Manipulating necessary header fields */
                iph->tot_len = htons(data_len + TOT_HDR_LEN);
                udph->len = htons(data_len + UDP_HDR_LEN);

                /* Calculation of IP header checksum */
                iph->check = 0;
                ip_send_check (iph);

                /* Calculation of UDP checksum */
                udph->check = 0;
                int offset = skb_transport_offset(skb);
                int len = skb->len - offset;
                udph->check = ~csum_tcpudp_magic((iph->saddr), (iph->daddr), len, IPPROTO_UDP, 0);
//	  printk(KERN_ALERT "Ethech zol aahe 2");
                 }
        }
    }
    return NF_ACCEPT;
}


module_init(pkt_mangle_init);
module_exit(pkt_mangle_exit);

