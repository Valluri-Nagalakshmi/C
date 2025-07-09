1.sliding window(indexing)
input string :"hihelloworld"
output : world
curr_len=0
initial index=0
first character      0  h ->1     [h]=1         index=0
second character     1	i->1      [hi]=2	    index=0
third character	     2	h->0      [hih]         index=0+1 ->index=1 [ih]->2
					 3	e->1      [ihe]->3	index=1
					 4	l-> 1     [ihel]->4	index =1
					 5	l->0      [ihell]       index(4+1) ->index =5 [ihel]->4
					 6	o->1      [lo]->2       ->no change    index =4
					 7	w->1      [low]->3      -> no change index =4
					 8	o->0     [lowo]        ->change  index=(6+1)->7 [wo]->2
					 9  r->1      [wor]->3      ->no  change    index=7
					 10	l->1      [worl]->4     ->here 4>4 so it takes previous substring index=7
					 11	d->1	  [world]->5     ->5>4 so max changes to 5 index=4
printing the substring to the string
take the index from the substring


2. Sliding window(pointers)
input string ="hihelloworld"
visit[256] = {0};
*start=*end=*start_ind=str;

0  h end ->h, start ->h, h->1, [h] cur_len = 1, max_len = 1, start_ind = start = 0; end++(h->i)
1  i end ->i, start ->h, i->1, [hi] cur_len =2, max_len =2, start_ind = 0; end++(i->h)
2  h end ->h, start ->h, h->0, window shrinks means before h is removed cur_len =2, max_len =2,start++(h->i)=1, start_ind = 1
2  h end ->h, start ->i, h->1, [ih] cur_len = 2, max_len = 2, start_ind = 1; end++(h->e)
3  e end ->e, start ->i, e->1, [ihe] cur_len = 3, max_len = 3, start_ind = 1; end++(e->l)
4  l end ->l, start ->i, l->1, [ihel] cur_len = 4, max_len =4, start_ind = 1; end++(l->l)
5  l end ->l, start ->i, l->0, window shrinks means before where 'l' occurs upto that it will shrink,those elements are removed  cur_len =4, max_len = 4, start++(i->l)=5, start_ind = 5; 
5  l end ->l, start ->l, l->1, [l] cur_len =1, max_len =4, start_ind = 5; end++(l->o)
6  o end ->o, start ->l, o->1, [lo] cur_len = 2, max_len =4, start_ind = 5; end++(o->w) 
7  w end ->w, start ->l, w->1, [low] cur_len = 3, max_len =4, start_ind = 5; end++(w->o)
8  o end ->o, start ->l, o->0, window shrinks means before where 'o' occurs upto that it will shrink,those elements are removed cur_len = 3, max_len = 4, start++(l->w)=7, start_ind = 7;
8  o end ->o, start ->w, o->1, [wo] cur_len = 2, max_len = 4, start_ind = 7; end++(o->r)
9  r end ->r, start ->w, r->1, [wor] cur_len =3, max_len =4, start_ind = 7; end++(r->l)
10 l end ->l, start ->w, l->1, [worl] cur_len =4, max_len =4, start_ind = 7; end++(l->d)
11 d end ->d, start ->d, d->1, [world] cur_len =5, max_len =5, start_ind = 7; there are no elements to increment end 

printing the sub string

we got start_ind: it the index number where our substring starts from their we are printing characters upto max_len.


3. brute force
input string str = "hihelloworld"
visit[256] = {0};
max_len = 0, start_ind = 0;

i=0, j=0 → 'h' → h=1 → [h] cur_len = 1, max_len = 1, start_ind = 0;
i=0, j=1 → 'i' → i=1 → [hi] cur_len = 2, max_len = 2, start_ind = 0;
i=0, j=2 → 'h' → already visited → break; max_len = 2, start_ind = 0;

i=1, j=1 → 'i' → i=1 → [i] cur_len = 1, max_len = 2, start_ind = 0;
i=1, j=2 → 'h' → h=1 → [ih] cur_len = 2, max_len = 2, start_ind = 0;
i=1, j=3 → 'e' → e=1 → [ihe] cur_len = 3, max_len = 3, start_ind = 1;
i=1, j=4 → 'l' → l=1 → [ihel] cur_len = 4, max_len = 4, start_ind = 1;
i=1, j=5 → 'l' → already visited → break; max_len = 4, start_ind = 1;

i=2, j=2 → 'h' → h=1 → [h] cur_len = 1, max_len = 4, start_ind = 1;
i=2, j=3 → 'e' → e=1 → [he] cur_len = 2, max_len = 4, start_ind = 1;
i=2, j=4 → 'l' → l=1 → [hel] cur_len = 3, max_len = 4, start_ind = 1;
i=2, j=5 → 'l' → already visited → break; max_len = 4, start_ind = 1;

i=3, j=3 → 'e' → e=1 → [e] cur_len = 1, max_len = 4, start_ind = 1;
i=3, j=4 → 'l' → l=1 → [el] cur_len = 2, max_len = 4, start_ind = 1;
i=3, j=5 → 'l' → already visited → break; max_len = 4, start_ind = 1;

i=4, j=4 → 'l' → l=1 → [l] cur_len = 1, max_len = 4, start_ind = 1;
i=4, j=5 → 'l' → already visited → break; max_len = 4, start_ind = 1;

i=5, j=5 → 'l' → l=1 → [l] cur_len = 1, max_len = 4, start_ind = 1;
i=5, j=6 → 'o' → o=1 → [lo] cur_len = 2, max_len = 4, start_ind = 1;
i=5, j=7 → 'w' → w=1 → [low] cur_len = 3, max_len = 4, start_ind = 1;
i=5, j=8 → 'o' → already visited → break; max_len = 4, start_ind = 1;

i=6, j=6 → 'o' → o=1 → [o] cur_len = 1, max_len = 4, start_ind = 1;
i=6, j=7 → 'w' → w=1 → [ow] cur_len = 2, max_len = 4, start_ind = 1;
i=6, j=8 → 'o' → already visited → break; max_len = 4, start_ind = 1;

i=7, j=7 → 'w' → w=1 → [w] cur_len = 1, max_len = 4, start_ind = 1;
i=7, j=8 → 'o' → o=1 → [wo] cur_len = 2, max_len = 4, start_ind = 1;
i=7, j=9 → 'r' → r=1 → [wor] cur_len = 3, max_len = 4, start_ind = 1;
i=7, j=10→ 'l' → l=1 → [worl] cur_len = 4, max_len = 4, start_ind = 1;
i=7, j=11→ 'd' → d=1 → [world] cur_len = 5, max_len = 5, start_ind = 7;

i=8, j=8 → 'o' → o=1 → [o] cur_len = 1, max_len = 5, start_ind = 7;
i=8, j=9 → 'r' → r=1 → [or] cur_len = 2, max_len = 5, start_ind = 7;
i=8, j=10→ 'l' → l=1 → [orl] cur_len = 3, max_len = 5, start_ind = 7;
i=8, j=11→ 'd' → d=1 → [orld] cur_len = 4, max_len = 5, start_ind = 7;

i=9, j=9 → 'r' → r=1 → [r] cur_len = 1, max_len = 5, start_ind = 7;
i=9, j=10→ 'l' → l=1 → [rl] cur_len = 2, max_len = 5, start_ind = 7;
i=9, j=11→ 'd' → d=1 → [rld] cur_len = 3, max_len = 5, start_ind = 7;

i=10, j=10 → 'l' → l=1 → [l] cur_len = 1, max_len = 5, start_ind = 7;
i=10, j=11→ 'd' → d=1 → [ld] cur_len = 2, max_len = 5, start_ind = 7;

i=11, j=11→ 'd' → d=1 → [d] cur_len = 1, max_len = 5, start_ind = 7;

printing the sub string

we got start_ind: it the index number where our substring starts from their we are printing characters upto max_len.


4. Bit masking
input str = "hihelloworld";
max_len = 0, start_ind = 0;


i=0, j=0 → 'h' → mask |= (1<<7) → [h] cur_len = 1, max_len = 1, start_ind = 0;
i=0, j=1 → 'i' → mask |= (1<<8) → [hi] cur_len = 2, max_len = 2, start_ind = 0;
i=0, j=2 → 'h' → already in mask → break; max_len = 2, start_ind = 0;

i=1, j=1 → 'i' → mask |= (1<<8) → [i] cur_len = 1, max_len = 2, start_ind = 0;
i=1, j=2 → 'h' → mask |= (1<<7) → [ih] cur_len = 2, max_len = 2, start_ind = 0;
i=1, j=3 → 'e' → mask |= (1<<4) → [ihe] cur_len = 3, max_len = 3, start_ind = 1;
i=1, j=4 → 'l' → mask |= (1<<11) → [ihel] cur_len = 4, max_len = 4, start_ind = 1;
i=1, j=5 → 'l' → already in mask → break; max_len = 4, start_ind = 1;

i=2, j=2 → 'h' → mask |= (1<<7) → [h] cur_len = 1, max_len = 4, start_ind = 1;
i=2, j=3 → 'e' → mask |= (1<<4) → [he] cur_len = 2, max_len = 4, start_ind = 1;
i=2, j=4 → 'l' → mask |= (1<<11) → [hel] cur_len = 3, max_len = 4, start_ind = 1;
i=2, j=5 → 'l' → already in mask → break; max_len = 4, start_ind = 1;

i=3, j=3 → 'e' → mask |= (1<<4) → [e] cur_len = 1, max_len = 4, start_ind = 1;
i=3, j=4 → 'l' → mask |= (1<<11) → [el] cur_len = 2, max_len = 4, start_ind = 1;
i=3, j=5 → 'l' → already in mask → break; max_len = 4, start_ind = 1;

i=4, j=4 → 'l' → mask |= (1<<11) → [l] cur_len = 1, max_len = 4, start_ind = 1;
i=4, j=5 → 'l' → already in mask → break; max_len = 4, start_ind = 1;

i=5, j=5 → 'l' → mask |= (1<<11) → [l] cur_len = 1, max_len = 4, start_ind = 1;
i=5, j=6 → 'o' → mask |= (1<<14) → [lo] cur_len = 2, max_len = 4, start_ind = 1;
i=5, j=7 → 'w' → mask |= (1<<22) → [low] cur_len = 3, max_len = 4, start_ind = 1;
i=5, j=8 → 'o' → already in mask → break; max_len = 4, start_ind = 1;

i=6, j=6 → 'o' → mask |= (1<<14) → [o] cur_len = 1, max_len = 4, start_ind = 1;
i=6, j=7 → 'w' → mask |= (1<<22) → [ow] cur_len = 2, max_len = 4, start_ind = 1;
i=6, j=8 → 'o' → already in mask → break; max_len = 4, start_ind = 1;

i=7, j=7 → 'w' → mask |= (1<<22) → [w] cur_len = 1, max_len = 4, start_ind = 1;
i=7, j=8 → 'o' → mask |= (1<<14) → [wo] cur_len = 2, max_len = 4, start_ind = 1;
i=7, j=9 → 'r' → mask |= (1<<17) → [wor] cur_len = 3, max_len = 4, start_ind = 1;
i=7, j=10→ 'l' → mask |= (1<<11) → [worl] cur_len = 4, max_len = 4, start_ind = 1;
i=7, j=11→ 'd' → mask |= (1<<3)  → [world] cur_len = 5, max_len = 5, start_ind = 7;

i=8, j=8 → 'o' → mask |= (1<<14) → [o] cur_len = 1, max_len = 5, start_ind = 7;
i=8, j=9 → 'r' → mask |= (1<<17) → [or] cur_len = 2, max_len = 5, start_ind = 7;
i=8, j=10→ 'l' → mask |= (1<<11) → [orl] cur_len = 3, max_len = 5, start_ind = 7;
i=8, j=11→ 'd' → mask |= (1<<3)  → [orld] cur_len = 4, max_len = 5, start_ind = 7;

i=9, j=9 → 'r' → mask |= (1<<17) → [r] cur_len = 1, max_len = 5, start_ind = 7;
i=9, j=10→ 'l' → mask |= (1<<11) → [rl] cur_len = 2, max_len = 5, start_ind = 7;
i=9, j=11→ 'd' → mask |= (1<<3)  → [rld] cur_len = 3, max_len = 5, start_ind = 7;

i=10, j=10 → 'l' → mask |= (1<<11) → [l] cur_len = 1, max_len = 5, start_ind = 7;
i=10, j=11→ 'd' → mask |= (1<<3)  → [ld] cur_len = 2, max_len = 5, start_ind = 7;

i=11, j=11→ 'd' → mask |= (1<<3)  → [d] cur_len = 1, max_len = 5, start_ind = 7;
