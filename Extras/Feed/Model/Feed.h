/*

BSD License

Copyright (c) 2004, Keith Anderson
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

*	Redistributions of source code must retain the above copyright notice,
	this list of conditions and the following disclaimer.
*	Redistributions in binary form must reproduce the above copyright notice,
	this list of conditions and the following disclaimer in the documentation
	and/or other materials provided with the distribution.
*	Neither the name of keeto.net or Keith Anderson nor the names of its
	contributors may be used to endorse or promote products derived
	from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


*/
#import <Foundation/Foundation.h>


#define FeedStatusDisabled @"Disabled"
#define FeedStatusChecking @"Checking"
#define FeedStatusIdle @"Idle"

#define FeedTypeRSS @"RSS"
#define FeedTypeAtom @"Atom"
#define FeedTypeUnknown @"Unknown"

#define FeedSource @"source"
#define FeedTitle @"title"
#define FeedUserTitle @"userTitle"
#define FeedSummary @"summary"
#define FeedLink @"link"
#define FeedType @"type"
#define FeedImage @"image"
#define FeedIcon @"icon"
#define FeedArticles @"articles"
#define FeedUniqueKey @"uniqueKey"
#define FeedPrefsKey @"prefs"


@class Article;
@interface Feed : NSObject <NSCoding> {
    NSString *          	source;
    NSString *          	title;
	NSString *				userTitle;
    NSString *				summary;
    NSString *				link;
    NSString *				type;
	NSString *				image;
	NSImage *				icon;
    NSMutableArray *    	articles;
	NSString *				error;
	NSString *				uniqueKey;
	NSMutableDictionary *	prefs;
}

-(id)initWithSource:(NSString *)aSource;
-(NSString *)cacheLocation;

-(NSString *)source;
-(NSString *)title;
-(NSString *)userTitle;
-(void)setUserTitle:(NSString *)aTitle;
-(NSString *)summary;
-(NSString *)link;
-(NSString *)type;
-(NSString *)image;
-(NSImage *)icon;
-(NSArray *)articles;

-(NSString *)error;
-(void)setError:(NSString *)reason;

-(void)expireArticles;
//-(void)sortArticles:(NSArray *)sortKeys;
-(void)addArticleFromDictionary:(NSDictionary *)dictionary;
-(void)updateFeedFromDictionary:(NSDictionary *)dictionary;

-(void)articlesWillUpdate;
-(void)articlesDidUpdate;

-(long)articleCount;
-(int)unreadArticleCount;
-(Article *)articleAtIndex:(long)anIndex;
-(Article *)articleForKey:(NSString *)key;
-(int)indexOfArticle:(Article *)anArticle;
-(void)removeArticle:(Article *)anArticle;
-(void)removeArticleAtIndex:(int)anIndex;

-(Article *)oldestUnread;
-(Article *)newestArticle;

@end