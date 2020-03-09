FeatureScript 1204;
import(path : "onshape/std/geometry.fs", version : "1204.0");

// import key hole part studio
KeyHole::import(path : "eef7d9464a896f67609b28fb", version : "489091dd647d34e46f9f700f");

annotation { "Feature Type Name" : "key hole" }
export const keyHole = defineFeature(function(context is Context, id is Id, definition is map)
precondition {
  annotation { "Name" : "Sketchoints tolace holes",
    "Filter" : BodyType.MATE_CONNECTOR,
  }
  definition.position is Query;

  annotation { "Name" : "Merge scope",
    "Filter" : (EntityType.BODY && BodyType.SOLID && ModifiableEntityOnly.YES),
    "MaxNumberOfPicks" : 1
  }
  definition.scope is Query;

  annotation { "Name" : "Base",
    "Filter" : (GeometryType.PLANE),
    "MaxNumberOfPicks" : 1
  }
  definition.base is Query;

  annotation { "Name" : "Stabilizer", "Default" : false }
  definition.hasStabilizer is boolean;
} {
  var thingTransform is Transform = toWorld(evMateConnector(context, {
     "mateConnector" : definition.mountingConnector
  }));

        var instantiator = newInstantiator(id + "instantiate");
        addInstance(instantiator, MyThing::build, { "transform" : thingTransform });
        instantiate(context, instantiator);

  var num = 0;
  for (var in evaluateQuery(context, definition.position)) {
    createKeyHole(context, id, num, p, definition);
    num += 1;
  }
});

function createKeyHole(context is Context, id is Id, num is number, pos is Query, definition is map) {
  var mate = evMateConnector(context, {
    "mateConnector" : pos
  });
  var holeId = id + num;

  var keyHoleSketch = ...

  var keepoutSketch = ...

  var gripSketch = 

  var extrudeDefinition = {
    "entities" : qSketchRegion(holeId + "keepoutSketch"),
    "direction" : mate.zAxis,
    "endBound" : BoundingType.UP_TO_BODY,
    "endBoundEntity" : definition.scope
  };

  opExtrude(context, holeId + "extrude_temp", extrudeDefinition);
  const bodyQuery = qCreatedBy(holeId + "extrude_temp", EntityType.BODY);
  const cylBox = evBox3d(context, { "topology" : bodyQuery, "cSys" : mate } );
  var lengthCarve = cylBox.maxCorner[2];
  opExtractSurface(context, holeId + "surface", {
    "faces" : qSketchRegion(holeId + "keepoutSketch"),
    "offset" : lengthCarve,
    "useFacesAroundToTrimOffset" : false
  });

  var gripDist = cylBox.maxCorner[2] + 1.5 * millimeter;
  opExtractSurface(context, holeId + "gripsurf", {
    "faces" : qSketchRegion(holeId + "gripSketch"),
    "offset" : gripDist, "useFacesAroundToTrimOffset" : false
  });

  opSweep(context, holeId + "sweep1", {
    "profiles" : qCreatedBy(holeId + "surface", EntityType.FACE),
    "path" : sketchEntityQuery(holeId + "line_plane", EntityType.EDGE, "linePlane"),
  });
  opBoolean(context, holeId + "boolean1", {
    "tools" : qCreatedBy(holeId + "sweep1", EntityType.BODY),
    "targets" : definition.scope,
    "operationType" : BooleanOperationType.SUBTRACTION
  });

  opSweep(context, holeId + "sweep2", {
    "profiles" : qCreatedBy(holeId + "gripsurf", EntityType.FACE),
    "path" : sketchEntityQuery(holeId + "line_plane", EntityType.EDGE, "linePlane2"),
  });
  opBoolean(context, holeId + "boolean2", {
    "tools" : qCreatedBy(holeId + "sweep2", EntityType.BODY),
    "targets" : definition.scope,
    "operationType" : BooleanOperationType.SUBTRACTION
  });

  opExtrude(context, holeId + "extrude1", {
    "entities" : qSketchRegion(holeId + "keyHoleSketch"),
    "direction" : mate.zAxis,
    "endBound" : BoundingType.THROUGH_ALL,
  });
  opBoolean(context, holeId + "boolean3", {
    "tools" : qCreatedBy(holeId + "extrude1", EntityType.BODY),
    "targets" : definition.scope,
    "operationType" : BooleanOperationType.SUBTRACTION
  });

  opDeleteBodies(context, holeId + "deleteBodies3", { "entities" : qCreatedBy(holeId + "surface") });
  opDeleteBodies(context, holeId + "deleteBodies4", { "entities" : qCreatedBy(holeId + "gripsurf") });
  opDeleteBodies(context, holeId + "deleteBodies5", { "entities" : qCreatedBy(holeId + "extrude_temp") });
}

