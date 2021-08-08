//Spawn helper function
void SpawnObject( string objectName, vector position, vector orientation )
{
    Object obj;
    obj = Object.Cast(GetGame().CreateObject(objectName, "0 0 0"));
    obj.SetPosition( position );
    obj.SetOrientation( orientation );

    // Force update collisions
    if ( obj.CanAffectPathgraph() )
    {
        obj.SetAffectPathgraph( true, false );
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
    }
}
