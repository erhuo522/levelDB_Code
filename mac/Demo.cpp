#include <leveldb/db.h>
#include <leveldb/db.h>


int main(int argc, char** argv)
{
    leveldb::DB* db;
    leveldb::Options options;
    // 如果打开已存在数据库的时候，需要抛出错误，将以下代码插在leveldb::DB::Open方法前面
    options.create_if_missing = true;
    // 打开一个数据库实例
    leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);
    assert(status.ok());
    // LevelDB提供了Put、Get和Delete三个方法对数据库进行添加、查询和删除
    std::string key = "key";
    std::string value = "value";
    // 添加key=value
    status = db->Put(leveldb::WriteOptions(), key, value);
    assert(status.ok());
    // 根据key查询value
    status = db->Get(leveldb::ReadOptions(), key, &value);
    assert(status.ok());
    
    // 修改操作（原生没有提供）由添加和删除合起来实现
    std::string key2 = "key2";
    // 添加key2=value
    status = db->Put(leveldb::WriteOptions(),key2,value);
    assert(status.ok());
    // 删除key
    status = db->Delete(leveldb::WriteOptions(), key);
    // 查询key2
    assert(status.ok());
    status = db->Get(leveldb::ReadOptions(), key2, &value);
    assert(status.ok());
                 // 查询key
    status = db->Get(leveldb::ReadOptions(), key, &value);
    if (!status.ok())
    {
        
    }
    else
    {
        
    }
    // 在对数据库进行了一系列的操作之后，需要对数据库进行关闭，该操作比较简单即删除该对象即可
    delete db;
    return 0;
}